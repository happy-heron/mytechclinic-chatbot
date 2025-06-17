# MY Tech Chatbot
---
## Technical Details
- Front-end is powered by TailwindCSS and basic HTML
- Front-end has the ability to feed user input into "Open"AI[^1] API (*ChatGPT*) or Anthropic API (*Claude*)
- The back-end is powered by C++ for performance and uses the "asio" library
- Questions from patrons are provided via a context file[^2], which must be located in the same directory as the executable
## API
### Client --> Server
- Client sends a POST request with the user's input via Javascript to an endpoint[^3]
### Client <-- Server
- Client receives data with the model's output back from the endpoint

[^1]: More like ***Closed***AI
[^2]: Specifically `context.md`
[^3]: Specifically `/6a187bbedb71b1917f5ea38d7c960a9a/d07ff2070a2d91dbe30e044a9189525e`
