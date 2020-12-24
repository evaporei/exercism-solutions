let validate = n => {
  let digits = n
    ->string_of_int
    ->Js.String.split("", _)
    ->Belt.Array.map(int_of_string);

  let exponent = float_of_int(Belt.Array.length(digits));

  let exponentials_sum = Belt.Array.reduce(
    digits,
    0,
    (acc, curr) => {
      let exponential = float_of_int(curr) ** exponent;

      acc + int_of_float(exponential)
    }
  );

  n === exponentials_sum
};
