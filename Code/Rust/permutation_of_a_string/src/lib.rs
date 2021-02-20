use std::io::{self, prelude::*};

pub fn get_input() -> Result<String, Box<dyn std::error::Error>> {
    let mut input_string = String::with_capacity(100);
    let stdin = io::stdin();
    let mut stdin = stdin.lock();
    let stdout = io::stdout();
    let mut stdout = stdout.lock();

    stdout.write(b"Enter the string to permute : ")?;
    stdout.flush()?;

    stdin.read_until(b' ', unsafe { input_string.as_mut_vec() })?;

    Ok(input_string)
}
