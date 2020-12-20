pub struct WordProblem;

pub fn answer(command: &str) -> Option<i32> {
    let result = command.replace("What is ", "").replace("?", "");
    result.parse::<i32>().ok()
}
