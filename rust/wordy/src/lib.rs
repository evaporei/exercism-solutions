use std::convert::TryFrom;

pub struct WordProblem;

pub fn answer(command: &str) -> Option<i32> {
    let tokens = command
        .replace("What is ", "")
        .replace("?", "")
        .split(" ")
        .map(Token::try_from)
        .collect::<Result<Vec<Token>, ()>>()
        .ok()?;

    AST::try_from(tokens)
        .ok()
        .map(i32::try_from)
        .map(Result::ok)
        .flatten()
}

enum Token {
    Number(i32),
    Plus,
}

impl TryFrom<&str> for Token {
    type Error = ();

    fn try_from(token: &str) -> Result<Self, Self::Error> {
        if let Ok(number) = token.parse::<i32>() {
            Ok(Token::Number(number))
        } else if token == "plus" {
            Ok(Token::Plus)
        } else {
            Err(())
        }
    }
}

enum AST {
    Operator(Box<AST>, Box<AST>, Box<AST>),
    Token(Token),
}

impl TryFrom<Vec<Token>> for AST {
    type Error = ();

    fn try_from(tokens: Vec<Token>) -> Result<Self, Self::Error> {
        tokens.windows(3).fold(Err(()), |acc, curr| acc)
    }
}

impl TryFrom<AST> for i32 {
    type Error = ();

    fn try_from(ast: AST) -> Result<Self, Self::Error> {
        Err(())
    }
}
