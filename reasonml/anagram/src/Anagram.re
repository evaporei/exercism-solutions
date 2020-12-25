let anagrams = (input, words) => Belt.List.keep(
  words,
  (word) => {
    if (Js.String.length(input) !== Js.String.length(word)) {
      false
    } else {
      let inputChars = Js.String.split("", input);
      Array.sort(compare, inputChars);

      let wordChars = Js.String.split("", word);
      Array.sort(compare, wordChars);

      compare(inputChars, wordChars) === 0
    }
  }
);
