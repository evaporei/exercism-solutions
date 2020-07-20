open Js.String;
open Js.Option;

let hey = input => {
  let trimmedInput = trim(input);
  let inputLen = length(trimmedInput);
  let isQuestion = get(trimmedInput, (inputLen - 1)) == "?";
  let isCapitalized =
    toUpperCase(trimmedInput) == trimmedInput &&
    isSome(match([%re "/[a-zA-Z]/g"], trimmedInput));
  let isEmpty = trimmedInput == "";

  switch (isQuestion, isCapitalized, isEmpty) {
    | (true, true, _) => "Calm down, I know what I'm doing!"
    | (_, _, true) => "Fine. Be that way!"
    | (true, _, _) => "Sure."
    | (_, true, _) => "Whoa, chill out!"
    | _ => "Whatever."
  };
};
