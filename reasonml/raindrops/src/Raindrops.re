let modulo = (n, m) => n mod m === 0;

let pling = n => switch (modulo(n, 3)) {
  | true => "Pling"
  | false => ""
};

let plang = n => switch (modulo(n, 5)) {
  | true => "Plang"
  | false => ""
};

let plong = n => switch (modulo(n, 7)) {
  | true => "Plong"
  | false => ""
};

let generic = string_of_int;

let raindrops = n => {
  let fns = [pling, plang, plong];

  switch (Belt.List.reduce(
    fns,
    "",
    (acc, fn) => {
      let result = fn(n);
      acc ++ result
    }
  )) {
    | "" => generic(n)
    | a => a
  }
};
