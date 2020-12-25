open Jest;
open Expect;
open Pangram;

describe("Pangram", () => {
  Skip.test("sentence empty", () =>
    expect(isPangram("")) |> toEqual(false) 
  );
  Skip.test("recognizes a perfect lower case pangram", () =>
    expect(isPangram("abcdefghijklmnopqrstuvwxyz")) |> toEqual(true) 
  );
  Skip.test("pangram with only lower case", () =>
    expect(isPangram("the quick brown fox jumps over the lazy dog")) |> toEqual(true) 
  );
  Skip.test("missing character 'x'", () =>
    expect(isPangram("a quick movement of the enemy will jeopardize five gunboats")) |> toEqual(false) 
  );
  Skip.test("another missing character, e.g. 'h'", () =>
    expect(isPangram("five boxing wizards jump quickly at it")) |> toEqual(false) 
  );
  Skip.test("pangram with underscores", () =>
    expect(isPangram("the_quick_brown_fox_jumps_over_the_lazy_dog")) |> toEqual(true) 
  );
  Skip.test("pangram with numbers", () =>
    expect(isPangram("the 1 quick brown fox jumps over the 2 lazy dogs")) |> toEqual(true) 
  );
  Skip.test("missing letters replaced by numbers", () =>
    expect(isPangram("7h3 qu1ck brown fox jumps ov3r 7h3 lazy dog")) |> toEqual(false) 
  );
  Skip.test("pangram with mixed case and punctuation", () =>
    expect(isPangram("\"Five quacking Zephyrs jolt my wax bed.\"")) |> toEqual(true) 
  );
  Skip.test("upper and lower case versions of the same character should not be counted separately", () =>
    expect(isPangram("the quick brown fox jumps over with lazy FX")) |> toEqual(false) 
  );
});
