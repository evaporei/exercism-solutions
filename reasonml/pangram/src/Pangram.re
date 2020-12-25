let chars = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"];

let isPangram = str =>
  List.for_all(char => char -> String.get(0) -> String.contains(str, _), chars);
