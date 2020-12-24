let raindrops = n => {
  let result = switch (n) {
    | n when n mod 3 === 0 => "Pling"
    | n when n mod 5 === 0 => "Plang"
    | _ => string_of_int(n)
  };

  result
};
