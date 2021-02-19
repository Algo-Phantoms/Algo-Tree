use clap::clap_app;

pub fn main() {
    let matches = clap_app!(AlgoTree =>
                            (version: "0.1.0")
                            (about: "Run all the algorithms!")
                            (@arg ALGO: +required "tell the algorithm to use")
        ).get_matches();

    match matches.value_of("ALGO").expect(matches.usage()) {
        s => println!("{}", s),
    }
}
