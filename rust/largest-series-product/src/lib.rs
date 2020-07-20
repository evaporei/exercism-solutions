#[derive(Debug, PartialEq)]
pub enum Error {
    SpanTooLong,
    InvalidDigit(char),
}

pub fn lsp(string_digits: &str, span: usize) -> Result<u64, Error> {
    return Err(Error::InvalidDigit(v_alphanumeric
                                   .first().unwrap()
                                   .to_owned()
                                   .to_string()
                                   .pop().unwrap()));

}
