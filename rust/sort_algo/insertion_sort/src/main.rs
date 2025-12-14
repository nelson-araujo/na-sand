use std::time::Instant;
use std::{io, usize};

use rand::seq::index;

fn main() {
    println!("\nInsertion Sort\n");

    // Get vector size from user
    let vec_length: u32 = get_vec_size();

    // Propulate vector with random numbers
    let unsorted_vec = set_unsort_vect(vec_length);

    // Insertion Sort
    println!("unsorted: {:?}", unsorted_vec);
    let mut start_time = Instant::now();
    let sorted_vec: Vec<u32> = insertion_sort(unsorted_vec);
    let insertion_sort_timer = start_time.elapsed();
    println!("\nsorted: {:?}", sorted_vec);
    println!("----------");

    // Display reuslts
    println!("\nResults\n-----------------------------");
    println!("Insertion Sort\t{:?}", insertion_sort_timer);
}

// Get the size of the vector to test form the user
fn get_vec_size() -> u32 {
    // Get user input
    println!("What size array would you like test?");

    let mut vec_length = String::new();
    io::stdin()
        .read_line(&mut vec_length)
        .expect("[ERROR] Unable to read from STDIN");

    // Convert user input to u32
    let vec_length: u32 = vec_length
        .trim()
        .parse()
        .expect("[ERROR] Unable to convert {vec_length} to u32");

    // return
    vec_length
}

// Populate the vector with random numbers
fn set_unsort_vect(size: u32) -> Vec<u32> {
    let mut vector = Vec::new();

    for _ in 1..=size {
        let rand_num = rand::random_range(1..=(size * 2));
        vector.push(rand_num);
    }

    // return
    vector
}

// Insertion sort
fn insertion_sort(unsorted: Vec<u32>) -> Vec<u32> {
    println!("\nInsertion Sort");
    let mut sorted = unsorted;

    // Get sidth of display columns (w=log10(lenght)+1)
    let col_width = ((sorted.len() as f32).log10() + 1.0).trunc() as usize;

    // sort the vector
    for index_to_sort in 1..sorted.len() {
        let mut index_to_compare_to = index_to_sort - 1;
        let mut temp_value = sorted[index_to_sort];

        // println!("temp_value: {:?}", temp_value);

        while index_to_compare_to >= 0 && index_to_sort <= sorted.len() {
            println!(
                "[{:>col_width$}]:{:<col_width$} =? [{:>col_width$}]:{:<col_width$}",
                index_to_sort,
                sorted[index_to_sort],
                index_to_compare_to,
                sorted[index_to_compare_to]
            );

            index_to_compare_to -= 1;
        }

        // Display values compared in this iteration
        // if sorted.len() < 20 {
        //     // Display the index, values being compared, and the end array
        //     println!(
        //         "[{:>col_width$}]:{:<col_width$} =? [{:>col_width$}]:{:<col_width$}\t{:?}",
        //         index_to_compare_to,
        //         sorted[index_to_compare_to],
        //         index_to_sort,
        //         sorted[index_to_sort],
        //         sorted
        //     );
        // } else {
        //     // Dispaly the index and values being compared but don't display the end array
        //     println!(
        //         "[{:>col_width$}]:{:<col_width$} =? [{:>col_width$}]:{:<col_width$}",
        //         index_to_compare_to,
        //         sorted[index_to_compare_to],
        //         index_to_sort,
        //         sorted[index_to_sort]
        //     );
        // }
    }

    // Return
    sorted
}
