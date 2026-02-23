// STring template
// console.log(`String templates`);
const myName = "Nelson"; // Don't use name since it's a reserved keyword
const age = 46;
const job = "enginer";

const nelson = `My name is ${myName}, I'm" a ${age} year old ${job}`;
// console.log(nelson);

// Multiline
// console.log(`\n\nMultipline string template`);
const nelson2 = `${myName}:
  - ${age} years old
  - ${job}`;

// console.log(nelson2);

// Switch statement
console.log(`\n\n Switch Statement \n`);
const day = "Monday";

switch (day) {
  case "Monday": // Day === "Monday"
    console.log(`Today is Monday`);
    break;

  case "Tuesday":
    console.log(`Today is Tuesday`);
    break;

  case "Wednesday": // Empty case with no break, it prints both Wednesday and Thrusday

  case "Thursday":
    console.log(`Today is Thursday`);
    break;

  case "Friday":
    console.log(`Today is Friday`);
}
