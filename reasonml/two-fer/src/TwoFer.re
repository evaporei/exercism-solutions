let personOrYou = (maybePerson) => switch (maybePerson) {
  | None => "you"
  | Some(name) => name
};

let twoFer = (maybeStr) => {
  let person = personOrYou(maybeStr);
  {j|One for $person, one for me.|j}
};
