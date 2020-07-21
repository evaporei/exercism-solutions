let wordCountReducer = (acc, word) => {
  let newCount = acc
    ->Js.Dict.get(word)
    ->Belt.Option.getWithDefault(0)
    ->(+)(1);
  Js.Dict.set(acc, word, newCount);
  acc;
}

let removeSpecialCharacters =
  Js.String.replaceByRe([%re "/[.,\\/#!$%\\^&\\*;:{}=\\-_`~()@]/g"], "", _)

let removeQuotations =
  Js.String.replaceByRe([%re "/'(\\w+)'/g"], "$1", _)

let removeNewLines =
  Js.String.replaceByRe([%re "/\\n/g"], " ", _)

let removeDoubleSpaces =
  Js.String.replaceByRe([%re "/  /g"], "", _)

let wordCount = phrase =>
  phrase
    ->removeSpecialCharacters
    ->removeQuotations
    ->removeNewLines
    ->removeDoubleSpaces
    ->Js.String.trim
    ->Js.String.split(" ", _)
    ->Belt.Array.map(Js.String.toLowerCase)
    ->Belt.Array.reduce(
        Js.Dict.empty(),
        wordCountReducer
      )
