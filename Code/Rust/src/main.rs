use clap::clap_app;

// importing all the algorithms
use wave_print;
use spiral_print;

const ALGOS: &'static str = r#"
spiral print
wave print
"#;

pub fn main() {
    let matches = clap_app!(AlgoTree =>
                            (version: "0.1.0")
                            (about: "Run all the algorithms!")
                            (@arg ALGO: +required "tell the algorithm to use")
        ).get_matches();

    match matches.value_of("ALGO").expect(matches.usage()) {
        "spiral_print" | "spiral print" => spiral_print::runner().unwrap(),
        "wave_print" | "wave print" => wave_print::runner().unwrap(),
        _ => panic!("Unknown algorithm used. choose from :{}", ALGOS),
    }
}
