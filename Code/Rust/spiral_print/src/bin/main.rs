use spiral_print::{get_input, spiral_print};

fn main() {
    let (arr, dim) = get_input().unwrap();
    spiral_print(arr, dim);
}
