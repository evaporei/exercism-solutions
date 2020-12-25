let areSameLength = (a, b) => Js.String.length(a) !== Js.String.length(b);

let equal = (a, b) => compare(a, b) === 0;

let anagrams = (input, words) => {
  let lowerCaseInput = Js.String.toLowerCase(input);
  let inputChars = Js.String.split("", lowerCaseInput);

  Array.sort(compare, inputChars);

  Belt.List.keep(
    words,
    (word) => {
      if (areSameLength(input, word)) {
        false
      } else {
        let lowerCaseWord = Js.String.toLowerCase(word);
        if (equal(lowerCaseInput, lowerCaseWord)) {
          false
        } else {
          let wordChars = Js.String.split("", lowerCaseWord);

          Array.sort(compare, wordChars);

          equal(inputChars, wordChars)
        }
      }
    }
  )
};
