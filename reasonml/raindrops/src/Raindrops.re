let raindrops = n => {
  let result = switch (n) {
    | n when n mod 3 === 0 => "Pling"
    | n when n mod 5 === 0 => "Plang"
    | n when n mod 7 === 0 => "Plong"
    | _ => string_of_int(n)
  };

  result
};
