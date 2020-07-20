pub trait Luhn: ToString {
    fn valid_luhn(&self) -> bool {
        let code = self.to_string();

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

impl<T: ToString> Luhn for T {}
