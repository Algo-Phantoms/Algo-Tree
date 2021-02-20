use std::io;
use std::str;

// TODO: add example usage.

/// It is used get fast input, in tokenized form for easy input. The input is taken in
/// whitespace-seperated form.
pub struct Scanner<R> {
    /// The reader from which mytes are read.
    reader: R,
    /// Buffer which stores additional bytes in case we needed less bytes then how many were
    /// parsed.
    buf_str: Vec<u8>,
    /// The whitespace-seperated iterator over `buf_str`.
    buf_iter: str::SplitAsciiWhitespace<'static>,
}

impl<R: io::BufRead> Scanner<R> {
    /// Create a new `Scanner` with the given reader.
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: Vec::new(),
            buf_iter: "".split_ascii_whitespace(),
        }
    }

    /// Get the next token from `reader`.
    pub fn get<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");

            // SAFETY: The `self.buf_iter` is created from `self.buf_str`, thus the iterator will
            // be invalidated as soon as the str itself will be. Thus there is no danger of
            // dangling pointers
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                // using `std::mem::transmute` to get static lifetime
                std::mem::transmute(slice.split_ascii_whitespace())
            };
        }
    }

    /// Get `Vec<T>` of a given length from reader.
    pub fn get_vec<T: str::FromStr>(&mut self, length: usize) -> Vec<T> {
        let mut arr = Vec::with_capacity(length);
        loop {
            while let Some(token) = self.buf_iter.next() {
                if arr.len() < length {
                    arr.push(token.parse().ok().expect("Failed parse"));
                } else {
                    break;
                }
            }

            if arr.len() == length {
                break;
            }

            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            };
        }
        arr
    }

    /// Get `[T; N]` of a given length from reader.
    pub fn get_arr<T: str::FromStr, const N: usize>(&mut self) -> [T; N] {
        use std::mem::MaybeUninit;

        // SAFETY: the loop wont exit until either array is filled or an error occurs. In both
        // cases this is fine.
        let mut arr: [T; N] = unsafe {
            MaybeUninit::uninit().assume_init()
        };
        let mut idx = 0;
        loop {
            while let Some(token) = self.buf_iter.next() {
                if idx < N {
                    arr[idx] = token.parse().ok().expect("Failed parse");
                    idx += 1;
                } else {
                    break;
                }
            }

            if idx == N {
                break;
            }

            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            // SAFETY: The `self.buf_iter` is created from `self.buf_str`, thus the iterator will
            // be invalidated as soon as the str itself will be. Thus there is no danger of
            // dangling pointers
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            };
        }
        arr
    }
}
