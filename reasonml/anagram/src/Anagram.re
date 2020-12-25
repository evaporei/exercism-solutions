let anagrams = (input, words) => {
  let inputChars = Js.String.split("", input)
    ->Belt.Array.map(Js.String.toLowerCase);

  Array.sort(compare, inputChars);

  Belt.List.keep(
    words,
    (word) => {
      if (Js.String.length(input) !== Js.String.length(word)) {
        false
      } else {
        let wordChars = Js.String.split("", word)
          ->Belt.Array.map(Js.String.toLowerCase);

        Array.sort(compare, wordChars);

        compare(inputChars, wordChars) === 0
      }
    }
  )
};
