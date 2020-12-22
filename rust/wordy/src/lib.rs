use std::convert::TryFrom;

pub struct WordProblem;

pub fn answer(command: &str) -> Option<i32> {
    let tokens = command
        .replace("What is ", "")
        .replace("?", "")
        .replace("by ", "")
        .split(" ")
        .map(Token::try_from)
        .collect::<Result<Vec<Token>, ()>>()
        .ok()?;

    // println!("tokens: {:?}", tokens);

    if tokens.len() == 1 {
        if let Ok(Token::Number(n)) = Token::try_from(tokens[0]) {
            return Some(n);
        }
    }

    let result = parse(tokens);
    // println!("result: {:?}", result);
    result.ok()
}

#[derive(Copy, Clone, Debug)]
enum Operator {
    Plus,
    Minus,
    Multiplication,
    Division,
}

impl Operator {
    fn operate(self, lhs: i32, rhs: i32) -> i32 {
        match self {
            Operator::Plus => lhs + rhs,
            Operator::Minus => lhs - rhs,
            Operator::Multiplication => lhs * rhs,
            Operator::Division => lhs / rhs,
        }
    }
}

#[derive(Copy, Clone, Debug)]
enum Token {
    Number(i32),
    Operator(Operator),
}

impl TryFrom<&str> for Token {
    type Error = ();

    fn try_from(token: &str) -> Result<Self, Self::Error> {
        if let Ok(number) = token.parse::<i32>() {
            return Ok(Token::Number(number));
        }

        match &token[..] {
            "plus" => Ok(Token::Operator(Operator::Plus)),
            "minus" => Ok(Token::Operator(Operator::Minus)),
            "multiplied" => Ok(Token::Operator(Operator::Multiplication)),
            "divided" => Ok(Token::Operator(Operator::Division)),
            _ => Err(()),
        }
    }
}

#[derive(Copy, Clone, Debug)]
struct State {
    lhs: Option<i32>,
    rhs: Option<i32>,
    operator: Option<Operator>,
    accumulator: i32,
}

impl State {
    fn new() -> Self {
        State {
            lhs: None,
            rhs: None,
            operator: None,
            accumulator: 0,
        }
    }
}

fn parse<'a>(tokens: Vec<Token>) -> Result<i32, &'a str> {
    let state = tokens.into_iter().fold(Ok(State::new()), |state, token| {
        let state = state?;
        // println!("state: {:?}", state);
        let state = match state {
            State {
                lhs: None,
                rhs: None,
                operator: None,
                accumulator,
            } => match token {
                Token::Number(number) => Ok(State {
                    lhs: Some(number),
                    ..state
                }),
                Token::Operator(operator) => match accumulator {
                    0 => Err("operator shoudn't be the first one"),
                    n => Ok(State {
                        lhs: Some(n),
                        operator: Some(operator),
                        accumulator: 0,
                        ..state
                    }),
                },
            },
            State {
                lhs: Some(_),
                rhs: None,
                operator: None,
                ..
            } => match token {
                Token::Number(_) => Err("should receive operator, not number"),
                Token::Operator(operator) => Ok(State {
                    operator: Some(operator),
                    ..state
                }),
            },
            State {
                lhs: Some(_),
                rhs: None,
                operator: Some(_),
                ..
            } => match token {
                Token::Number(number) => Ok(State {
                    rhs: Some(number),
                    ..state
                }),
                Token::Operator(_) => Err("should receive right side number, not operator"),
            },
            _ => Err("none of the cases hmmm"),
        };

        if let State {
            lhs: Some(lhs),
            rhs: Some(rhs),
            operator: Some(operator),
            accumulator,
        } = state?
        {
            Ok(State {
                lhs: None,
                rhs: None,
                operator: None,
                accumulator: accumulator + operator.operate(lhs, rhs),
            })
        } else {
            state
        }
    });
    Ok(state?.accumulator)
}
