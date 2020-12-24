open Jest;

describe("Armstrong Numbers", () => {
  open Expect;

  Skip.test("Single digit numbers are Armstrong numbers", () =>
    expect(ArmstrongNumbers.validate(5)) |> toBe(true)
  );

  Skip.test("There are no 2 digit Armstrong numbers", () =>
    expect(ArmstrongNumbers.validate(10)) |> toBe(false)
  );

  Skip.test("Three digit number that is an Armstrong number", () =>
    expect(ArmstrongNumbers.validate(153)) |> toBe(true)
  );

  Skip.test("Three digit number that is not an Armstrong number", () =>
    expect(ArmstrongNumbers.validate(100)) |> toBe(false)
  );

  Skip.test("Four digit number that is an Armstrong number", () =>
    expect(ArmstrongNumbers.validate(9474)) |> toBe(true)
  );

  Skip.test("Four digit number that is not an Armstrong number", () =>
    expect(ArmstrongNumbers.validate(9475)) |> toBe(false)
  );

  Skip.test("Seven digit number that is an Armstrong number", () =>
    expect(ArmstrongNumbers.validate(9926315)) |> toBe(true)
  );

  Skip.test("Seven digit number that is not an Armstrong number", () =>
    expect(ArmstrongNumbers.validate(9926314)) |> toBe(false)
  );
});
