let anagrams = (input, words) => {
  let lowerCaseInput = Js.String.toLowerCase(input);
  let inputChars = Js.String.split("", lowerCaseInput);

  Array.sort(compare, inputChars);

  Belt.List.keep(
    words,
    (word) => {
      if (Js.String.length(input) !== Js.String.length(word)) {
        false
      } else {
        let lowerCaseWord = Js.String.toLowerCase(word);
        if (compare(lowerCaseInput, lowerCaseWord) === 0) {
          false
        } else {
          let wordChars = Js.String.split("", lowerCaseWord);

          Array.sort(compare, wordChars);

          compare(inputChars, wordChars) === 0
        }
      }
    }
  )
};
