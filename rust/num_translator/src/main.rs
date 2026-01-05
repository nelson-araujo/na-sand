use std::io;
use std::io::Write;

fn main() {
    println!("Num Translator: Convert decimal to hex and binary");

    let user_num = get_user_num();

    // Print table to user
    println!("\nDecimal\tHex\tBinary");
    print_table_row(user_num, get_hex(user_num), get_bin(user_num));
}

// Get user number to translate
fn get_user_num() -> u32 {
    let mut user_input_strg = String::new();

    // Prompt the user and force line to display with stdout().flush()
    print!("Enter a number to translate: ");
    io::stdout().flush().expect("Failed to flush stdout");
    io::stdin().read_line(&mut user_input_strg).unwrap();

    // convert String to u32
    let user_input_num:u32 = user_input_strg.trim().parse().expect("[ERR ] Non-number entered!");

    return user_input_num;
}

// Receive u32 decimal and return hex as String
fn get_hex(num: u32) -> String {
    return format!("{num:x}");
}

// Receive a u32 decimal and return binary as String
fn get_bin(num: u32) -> String {
    return format!("{:b}", num);
}

// Print table row to stdout
fn print_table_row(num:u32, hex:String, binary:String){
    println!("{}\t{}\t{}", num, hex, binary);
}
