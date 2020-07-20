open Belt.List;

type dna =
  | A
  | C
  | G
  | T

type rna =
  | A
  | C
  | G
  | U

let mapDnaToRna = (dna: dna): rna => switch (dna) {
  | G => C
  | C => G
  | T => A
  | A => U
}

let toRna = map(_, mapDnaToRna)
