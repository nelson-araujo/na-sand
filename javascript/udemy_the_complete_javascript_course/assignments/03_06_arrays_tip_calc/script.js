"use strict";

let totals = [];
const bills = [125, 555, 44];

function calcTip(billAmount) {
  if (billAmount > 50 && billAmount < 300) {
    return billAmount * 0.15;
  } else {
    return billAmount * 0.2;
  }
}

for (let i = 0; i < bills.length; i++) {
  totals[i] = bills[i] + calcTip(bills[i]);
}

console.log(`${bills}`);
console.log(`${totals}`);
