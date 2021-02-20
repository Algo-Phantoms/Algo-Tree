use std::io::{self, prelude::*};

// importing scanner
use io_tokenized::Scanner;

pub fn get_input() -> Result<([[i32; 30]; 30], usize), Box<dyn std::error::Error>> {
    let stdin = io::stdin();
    let mut scanner = Scanner::new(stdin.lock());
    let stdout = io::stdout();
    let mut stdout = stdout.lock();

    // reading dims
    stdout.write(b"Enter dimensions : ")?;
    stdout.flush()?;
    let dims: usize = scanner.get();

    // panic is buffer size exceeded
    if dims > 30 {
        panic!("dimensions exceeded! Keep below 30.");
    }

    // initializing the array
    let mut arr = [[0i32; 30]; 30];

    // get `arr` input
    stdout.write(b"Enter the array row-wise :\n")?;
    stdout.flush()?;
    for i in 0..dims {
        for (j, elem) in scanner.get_vec::<i32>(dims).into_iter().enumerate() {
            arr[i][j] = elem;
        }
    }

    Ok((arr, dims))
}

pub fn spiral_print(arr: [[i32; 30]; 30], dim: usize) {
    if dim == 1 {
        println!("{}", arr[0][0]);
        return;
    }
    // keeping track of 4 sides:
    let (mut top, mut left, mut bottom, mut right) = (0, 0, dim - 1, dim - 1);

    for _ in 0..if dim % 2 == 0 { dim / 2 } else { dim / 2 + 1 } {
        // the top
        for i in left..=right {
            print!("{}\t", arr[top][i]);
        }
        top += 1;

        // the left
        for i in top..=bottom {
            print!("{}\t", arr[i][right]);
        }
        right -= 1;

        // the bottom
        for i in (left..=right).rev() {
            print!("{}\t", arr[bottom][i]);
        }
        bottom -= 1;

        // the left
        for i in (top..=bottom).rev() {
            print!("{}\t", arr[i][left]);
        }
        left += 1;
    }

    println!();
}

pub fn runner() -> Result<(), Box<dyn std::error::Error>> {
    let (arr, dim) = get_input()?;
    spiral_print(arr, dim);
    Ok(())
}
