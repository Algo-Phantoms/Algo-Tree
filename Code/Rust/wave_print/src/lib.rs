use std::io::{self, prelude::*};

pub fn get_input() -> Result<([[i32; 30]; 30], usize, usize), Box<dyn std::error::Error>> {
    // string which will take input
    let mut input_string = String::new();

    // locking stdin and stdout for speed
    let stdin = io::stdin();
    let mut stdin = stdin.lock();
    let stdout = io::stdout();
    let mut stdout = stdout.lock();

    // reading dims
    stdout.write(b"Enter dimensions : ")?;
    stdout.flush()?;
    stdin.read_line(&mut input_string)?;
    let mut dims = input_string.split_whitespace();
    let rows = dims.next().ok_or("Expected rows")?.parse::<usize>()?;
    let cols = dims.next().ok_or("Expected rows")?.parse::<usize>()?;

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
        input_string.clear();
        stdin.read_line(&mut input_string)?;
        for (j, s) in input_string.split_whitespace().enumerate() {
            if j > 30 {
                panic!("Expected {} elements", cols);
            }
            arr[i][j] = s.parse()?;
        }
    }

    Ok((arr, rows, cols))
}

pub fn wave_print(arr: [[i32; 30]; 30], rows: usize, cols: usize) {
    let going_up = false;

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
    }

    println!();
}
