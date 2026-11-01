# SIGNAL
### Decoding & Encoding Bureau
**Established 1924**

SIGNAL is a C++ terminal-based encoding and decoding program inspired by vintage intelligence agencies and communication systems.

It brings together several encoding methods, classical ciphers, number systems, and a small decoding challenge in one place.

---

## Features

### Encoding & Decoding
- **Morse Code** – Convert text to Morse code and Morse code back to text.
- **Number Systems** – Convert decimal numbers to binary and hexadecimal, and decode them back to decimal.
- **Classical Ciphers**
  - Caesar Cipher (encode and decode)
  - Atbash Cipher
  - Vigenère Cipher (encode and decode)
- **ASCII** – Convert text into ASCII values and back.
- **A1Z26** – Replace letters with their positions in the alphabet and decode them.
- **NATO Phonetic Alphabet** – Convert letters into NATO code words and back.

### Additional Features
- **Message History** – View previous conversions or clear the history.
- **Challenge Mode** – Decode five randomly generated messages using Caesar, Atbash, and A1Z26.
- **Scoring System** – Earn points and receive a rank based on your challenge performance.
- **Input Validation** – Basic validation for menu choices and supported input formats.

---

## How to run
Open the Releases page.

Download SIGNAL.exe from the latest release.

Follow the on-screen menu to select a message decoding or encoding category.

Enter the message you want to decode or encode, convert it and view the result.

Follow the menu options to perform another decoding or encoding or exit the application.


The project is currently written in a single C++ source file.

---

## How It Works

When the program starts, a main menu allows you to choose between the available encoding and decoding tools.

Each tool has its own submenu with instructions where applicable. Converted messages are added to the message history during the current session.

Challenge Mode generates five messages using different encoding methods. The player must decode each message and receives a final rank:

| Score | Rank |
|---|---|
| 5/5 | MASTER |
| 3–4/5 | AGENT |
| 0–2/5 | TRAINEE |

---

## Technologies Used

- **C++**
- Standard C++ libraries:
  - `iostream`
  - `string`
  - `sstream`
  - `cctype`
  - `limits`
  - `vector`
  - `ctime`
  - `cstdlib`

---

## Notes & Limitations

- Message history is stored in memory and is cleared when the program closes.
- Challenge Mode uses a predefined collection of five words.
- The program is designed for terminal use; it does not have a graphical interface.
- The encoding methods are educational implementations and should not be used to protect sensitive information.

---

## About

SIGNAL is a beginner C++ project created for Terra (program by Hack Club) by SpagettiMaff.

**SIGNAL — Decoding the unknown since 1924.**
