use std::io;
// use rand::Rng; // Deprecated
use std::cmp::Ordering;

fn main() {
    println!("\nGuess the number!\n");

    // Deprecated
    // let secret_number = rand::thread_rng().gen_range(1..=100);

    // Generate a random number between 1 and 100
    let secret_number = rand::random_range(1..=100);

    // TODO - debug message
    println!("[DEBUG] random number is {secret_number}");
    
    loop{
        println!("Enter your guess:");
        
        let mut guess = String::new();
        
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");
        
        // convert String to u32
        // let guess: u32 = guess.trim().parse().expect("Please type a number!");
        let guess:u32 = match guess.trim().parse(){
            Ok(num) => num,
            Err(_) => continue,
        };
        
        println!("You guessed: {guess}");
        
        match guess.cmp(&secret_number){
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("Got it!");
                break;
            }
        }
    }
}
