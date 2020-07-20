type planet =
  | Mercury
  | Venus
  | Earth
  | Mars
  | Jupiter
  | Saturn
  | Neptune
  | Uranus

let earthYearInSeconds: float = 31557600.0

let timesEarthInSeconds = (multiplier) =>
  earthYearInSeconds *. multiplier

let getPlanetEarthMultiplier =
  fun
  | Earth => 1.0
  | Mercury => 0.2408467
  | Venus => 0.61519726
  | Mars => 1.8808158
  | Jupiter => 11.862615
  | Saturn => 29.447498
  | Uranus => 84.016846
  | Neptune => 164.79132

let secondsDividedOn = (n, seconds) => seconds /. n

let ageOn = (p, seconds) =>
  p
    ->getPlanetEarthMultiplier
    ->timesEarthInSeconds
    ->secondsDividedOn(seconds)
