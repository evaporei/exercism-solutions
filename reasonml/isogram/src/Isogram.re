let reducer = ((acc, keepSearching), curr) => {
  if (keepSearching) {
    let newCount = acc
      ->Js.Dict.get(curr)
      ->Belt.Option.getWithDefault(0)
      ->(+)(1);

    if (newCount > 1) {
      (acc, false)
    } else {
      Js.Dict.set(acc, curr, newCount);
      (acc, true)
    }
  } else {
    (acc, false)
  }
};

let is_isogram = str => str
  ->Js.String.replace("-", "", _)
  ->String.lowercase
  ->Js.String.split("", _)
  ->Belt.Array.reduce(
    (Js.Dict.empty(), true),
    reducer
  )
  ->snd;
