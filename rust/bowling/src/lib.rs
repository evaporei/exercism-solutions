#[derive(Debug, PartialEq)]
pub enum Error {
    NotEnoughPinsLeft,
    GameComplete,
}

#[derive(Default)]
pub struct BowlingGame {
    rolls: Vec<u16>,
    frames: Vec<Vec<u16>>,
}

impl BowlingGame {
    pub fn new() -> Self {
        Self::default()
    }

    pub fn roll(&mut self, pins: u16) -> Result<(), Error> {
        if pins > 10 {
            return Err(Error::NotEnoughPinsLeft);
        }

        self.rolls.push(pins);

        if self.is_strike() {
            self.frames.push(vec![pins]);
        } else if self.is_spare() {
            self.frames.push(vec![pins]);
        }

        Ok(())
    }

    fn is_strike(&self) -> bool {
        let rolls_len = self.rolls.len();
        self.rolls[rolls_len - 1] == 10
    }

    fn is_spare(&self) -> bool {
        let rolls_len = self.rolls.len();
        (self.rolls[rolls_len - 1] + self.rolls[rolls_len - 2]) == 10
    }

    pub fn score(&self) -> Option<u16> {
        unimplemented!("Return the score if the game is complete, or None if not.");
    }
}
