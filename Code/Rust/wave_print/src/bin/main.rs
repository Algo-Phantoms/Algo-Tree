use wave_print::{get_input, wave_print};

fn main() {
    let (arr, rows, cols) = get_input().unwrap();
    wave_print(arr, rows, cols);
}
