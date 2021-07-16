use std::io;

fn main() {
    //println!("Hello, world!");
    println!("Garrett's guessing game!");

    println!("Please input your guess.");

    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Error: Failed to read line!");
    
    println!("You guessed: {}", guess);
}
