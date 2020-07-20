let isDivisibleByN = (by, n) => n mod by === 0;

let isDivisibleBy4 = isDivisibleByN(4);
let isDivisibleBy100 = isDivisibleByN(100);
let isDivisibleBy400 = isDivisibleByN(400);

let isLeapYear = (year) =>
  isDivisibleBy4(year) &&
  (!isDivisibleBy100(year) || isDivisibleBy400(year));
