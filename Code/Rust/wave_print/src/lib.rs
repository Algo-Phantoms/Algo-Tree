use std::io::{self, prelude::*};

// importing scanner
use io_tokenized::Scanner;

pub fn get_input() -> Result<([[i32; 30]; 30], usize, usize), Box<dyn std::error::Error>> {
    let stdin = io::stdin();
    let mut scanner = Scanner::new(stdin.lock());
    let stdout = io::stdout();
    let mut stdout = stdout.lock();

    // reading dims
    stdout.write(b"Enter dimensions : ")?;
    stdout.flush()?;
    let rows: usize = scanner.get();
    let cols: usize = scanner.get();

    // panic is buffer size exceeded
    if rows > 30 || cols > 30 {
        panic!("dimensions exceeded! Keep below 30.");
    }

    // initializing the array
    let mut arr = [[0i32; 30]; 30];

    // get `arr` input
    stdout.write(b"Enter the array row-wise :\n")?;
    stdout.flush()?;
    for i in 0..rows {
        for (j, elem) in scanner.get_vec::<i32>(cols).into_iter().enumerate() {
            arr[i][j] = elem;
        }
    }

    Ok((arr, rows, cols))
}

pub fn wave_print(arr: [[i32; 30]; 30], rows: usize, cols: usize) {
    let mut going_up = false;

    for col in 0..cols {
        if going_up {
            for row in (0..rows).rev() {
                print!("{}\t", arr[row][col]);
            }
        } else {
            for row in 0..rows {
                print!("{}\t", arr[row][col]);
            }
        }
        going_up = !going_up;
    }

    println!();
}

pub fn runner() -> Result<(), Box<dyn std::error::Error>> {
    let (arr, rows, cols) = get_input()?;
    wave_print(arr, rows, cols);
    Ok(())
}
