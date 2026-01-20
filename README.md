# Escape Box

An Arduino-based puzzle box that runs escape-room style games. Players solve puzzles by entering codes using a keypad and colored buttons, with correct solutions unlocking physical doors or revealing story clues.

## Features

- Multiple puzzle games with different themes and storylines
- Two input methods: 4x4 numeric keypad and 4 colored buttons (Red, Green, Blue, Yellow)
- ST7789 TFT display (240x320) for menus, prompts, and clues
- Two door mechanisms triggered by puzzle completion
- Extensible game architecture for adding new puzzle sets

## Hardware Requirements

- Arduino board
- ST7789 TFT Display (240x320)
- 4x4 Matrix Keypad
- 4 Colored Buttons (Red, Green, Blue, Yellow)
- 2 Door/Lock mechanisms (solenoid or servo)

### Pin Configuration

| Component | Pin |
|-----------|-----|
| TFT CS | 10 |
| TFT RST | 9 |
| TFT DC | 8 |
| Keypad Rows | 7, 0, 1, 3 |
| Keypad Cols | 2, 4, 5, 6 |
| Door 1 | A0 |
| Door 2 | A1 |
| Red Button | A2 |
| Green Button | A3 |
| Blue Button | A4 |
| Yellow Button | A5 |

## Dependencies

- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit ST7735/ST7789 Library](https://github.com/adafruit/Adafruit-ST7735-Library)

Install via Arduino Library Manager or PlatformIO.

## Games

### EasterGame
A themed puzzle set with 6 puzzles involving keypad codes and color sequences. Solving puzzles reveals clues that guide players through the experience.

### InheritanceGame
A story-driven puzzle set with 6 puzzles. Players uncover narrative clues about a character's memories as they progress.

## Architecture

```
EscapeGame (base class)
├── EasterGame
└── InheritanceGame
```

- **EscapeGame**: Abstract base class providing common functionality (display text, read codes, open doors)
- **PuzzleKeyPad**: 4x4 keypad input handler
- **Game implementations**: Define puzzle menus, codes, and clues

## Adding a New Game

1. Create a new class inheriting from `EscapeGame`
2. Implement required methods:
   - `Setup()` - Initialize game state and set `numPuzzles`
   - `GameLoop()` - Main game loop
   - `drawMenu()` - Display puzzle selection menu
   - `runPuzzle(int puzzleId)` - Handle individual puzzle logic
3. Add the game to `escape_box.ino`

## Usage

1. Upload the sketch to your Arduino
2. Select a puzzle from the on-screen menu using the keypad (1-6)
3. Enter the required code using the keypad or colored buttons
4. Press `#` to exit a puzzle and return to the menu
5. Correct codes display clues or trigger door mechanisms

## License

See [LICENSE](LICENSE) for details.
