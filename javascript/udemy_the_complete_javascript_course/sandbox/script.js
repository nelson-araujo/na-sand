// STring template
console.log(`String templates`);
const myName = "Nelson"; // Don't use name since it's a reserved keyword
const age = 46;
const job = "enginer";

const nelson = `My name is ${myName}, I'm" a ${age} year old ${job}`;
console.log(nelson);

// Multiline
console.log(`\n\nMultipline string template`);
const nelson2 = `${myName}:
  - ${age} years old
  - ${job}`;

console.log(nelson2);
