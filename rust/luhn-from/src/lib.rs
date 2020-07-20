pub struct Luhn(String);

impl Luhn {
    pub fn is_valid(&self) -> bool {
        let code = &self.0;

        if code.trim().len() <= 1 {
            return false;
        }

        if !code.chars().all(|ch| ch.is_digit(10) || ch.is_whitespace()) {
            return false;
        }

        let numbers_sum: u32 = code
            .chars()
            .rev()
            .filter_map(|ch| ch.to_digit(10))
            .enumerate()
            .map(|(i, n)|
                 match i % 2 {
                     0 => n,
                     _ if n == 9 => n,
                     _ => (n * 2) % 9,
                 }
            )
            .sum();

        numbers_sum % 10 == 0
    }
}

/// Here is the example of how the From trait could be implemented
/// for the &str type. Naturally, you can implement this trait
/// by hand for the every other type presented in the test suite,
/// but your solution will fail if a new type is presented.
/// Perhaps there exists a better solution for this problem?
impl<T> From<T> for Luhn where T: ToString {
    fn from(input: T) -> Self {
        Self(input.to_string())
    }
}
