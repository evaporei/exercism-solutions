let raindrops = n => {
  let result = switch (n) {
    | n when n mod 3 === 0 => "Pling"
    | _ => string_of_int(n)
  };

  result
};
