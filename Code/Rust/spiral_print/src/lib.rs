use std::io::{self, prelude::*};

// TODO: refactor using `Scanner`
pub fn get_input() -> Result<([[i32; 30]; 30], usize), Box<dyn std::error::Error>> {
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
    let dims = input_string
        .split_whitespace()
        .next()
        .ok_or("Expected dims")?
        .parse::<usize>()?;

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
        input_string.clear();
        stdin.read_line(&mut input_string)?;
        for (j, s) in input_string.split_whitespace().enumerate() {
            arr[i][j] = s.parse()?;
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
            println!("{}\t", arr[top][i]);
        }
        top += 1;

        // the left
        for i in top..=bottom {
            println!("{}\t", arr[i][right]);
        }
        right -= 1;

        // the bottom
        for i in (left..=right).rev() {
            println!("{}\t", arr[bottom][i]);
        }
        bottom -= 1;

        // the left
        for i in (top..=bottom).rev() {
            println!("{}\t", arr[i][left]);
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
