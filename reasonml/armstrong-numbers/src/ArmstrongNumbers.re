let validate = n => {
  let digits = n
    ->string_of_int
    ->Js.String.split("", _)
    ->Belt.Array.map(int_of_string);

  let pow = float_of_int(n) ** float_of_int(Belt.Array.length(digits));

  n === int_of_float(pow)
};
