open Jest;

describe("Isograms", () => {
  open Expect;

  test("Empty string", () =>
    expect(Isogram.is_isogram("")) |> toBe(true)
  );

  test("Isogram with only lower case characters", () =>
    expect(Isogram.is_isogram("isogram")) |> toBe(true)
  );

  test("Word with one duplicated character", () =>
    expect(Isogram.is_isogram("eleven")) |> toBe(false)
  );

  test("Longest reported english isogram", () =>
    expect(Isogram.is_isogram("subdermatoglyphic")) |> toBe(true)
  );

  Skip.test("Word with duplicated character in mixed case", () =>
    expect(Isogram.is_isogram("Alphabet")) |> toBe(false)
  );

  Skip.test("Hypothetical isogrammic word with hyphen", () =>
    expect(Isogram.is_isogram("thumbscrew-japingly")) |> toBe(true)
  );

  Skip.test("Isogram with duplicated hyphen", () =>
    expect(Isogram.is_isogram("six-year-old")) |> toBe(true)
  );

  Skip.test("Made-up name that is an isogram", () =>
    expect(Isogram.is_isogram("Emily Jung Schwartzkopf")) |> toBe(true)
  );

  Skip.test("Duplicated character in the middle", () =>
    expect(Isogram.is_isogram("accentor")) |> toBe(false)
  );
});
