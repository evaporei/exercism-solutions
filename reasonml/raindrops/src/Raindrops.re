let modulo = (n, m) => n mod m === 0;

let factors = [
  (3, "Pling"),
  (5, "Plang"),
  (7, "Plong"),
];

let reducer = n => (acc, (factor, str)) =>
  modulo(n, factor)
    ? acc ++ str
    : acc ++ "";

let raindrops = n => {
  switch (Belt.List.reduce(
    factors,
    "",
    reducer(n)
  )) {
    | "" => string_of_int(n)
    | s => s
  }
};
