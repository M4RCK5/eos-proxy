# EOS Proxy

A stupid simple Epic Online Services "proxy" that enables multiplayer functionality in some Steam games that use EOS.

# How to use

- Rename the existing `EOSSDK-Win64-Shipping.dll` in the game folder to `EOSSDK-Win64-Shipping.yes`
- Download the proxy dll from [releases](https://github.com/yesyes0649/eos-proxy/releases) and put it in the same location
- Additionally, most games seem to **require** `ISteamUser::GetAuthTicketForWebApi` to return a non-error response before they even call the EOS networking functions. So you will have to use one of the following:
  - (Linux only) [SLSsteam](https://github.com/AceSLS/SLSsteam/) with [FakeAppIds](https://github.com/AceSLS/SLSsteam/wiki/Configuration#fakeappids-map-of-positive-number--positive-number) configured for the game
  - [uc-online2](https://github.com/UnionCrax-Team/uc-online2), which provides an experience that is very similar to Online-Fix
  - If you want to run the game independent of Steam, use [gbe_fork](https://github.com/Detanup01/gbe_fork/)
- Regardless of which option you choose, you're good to go. All multiplayer is still handled through Epic, so aside from steam invites being incompatible between gbe_fork and the other two, there should be no other compatibility issues
- In case of issues, check the `epic_proxy.log` file next to game executable. Feel free to open an issue in GitHub.

# Confirmed Games

I've only tested this with a few games.

- Sledding Game
- SpiderHeck (this one has an incompatibility with gbe_fork. Use the other two options.)
- Absolum (needs some additional changes. Check the `absolum` branch.)

# How it works

- All games that use EOS first call a `EOS_Connect_Login` function to initialize networking features. Since Epic supports a wide variety of platforms, they have many different authentication choices.
- This proxy just intercepts that function call, and swaps the authentication type from `EOS_ECT_STEAM_SESSION_TICKET` (which requires a valid steam auth ticket) to `EOS_ECT_DEVICEID_ACCESS_TOKEN` (which requires nothing. it's a game-specific and device-specific token.). There is a bit more code to prepare the device id access token, but that's all.


# Disclaimer / Credits

Developers can choose to disable this login option. Therefore this proxy is not going to work for every game. This work isn't original at all, so here are some credits:

- Online-Fix for the approach used. Others may have done it but my approach is entirely based on their fixes.
- Functions for logging (in `logger.c`) and fetching Steam ID / persona name (in `steam.h`) are slop (by Claude)
