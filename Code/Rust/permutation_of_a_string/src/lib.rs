use std::io::{self, prelude::*};

use io_tokenized::Scanner;

pub fn get_input() -> Result<Vec<u8>, Box<dyn std::error::Error>> {
    let stdin = io::stdin();
    let mut scanner = Scanner::new(stdin.lock());
    let stdout = io::stdout();
    let mut stdout = stdout.lock();

    stdout.write(b"Enter the string to permute : ")?;
    stdout.flush()?;

    Ok(scanner.get::<String>().as_bytes().to_vec())
}

pub fn permutation(arr: &mut Vec<u8>, idx: usize) -> Result<(), Box<dyn std::error::Error>> {
    if idx >= arr.len() {
        println!("{}", std::str::from_utf8(&arr[..]).unwrap());
    }

    for i in idx..arr.len() {
        arr.swap(i, idx);
        permutation(arr, idx + 1)?;
        arr.swap(i, idx);
    }

    Ok(())
}

pub fn runner() -> Result<(), Box<dyn std::error::Error>> {
    permutation(&mut get_input()?, 0)?;
    Ok(())
}
