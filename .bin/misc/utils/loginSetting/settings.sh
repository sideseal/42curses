#!/bin/bash

#sleep 10; launchctl load /System/Library/LaunchDaemons/com.apple.securityd.plist

#pkill -u "${USER}" -f "^/System/Applications/System Preferences.app/Contents/MacOS/System Preferences$" 2>/dev/null
osascript -e 'tell application "System Preferences" to quit'

# Keyboard/Delay Until Repeat (Long: 120 <---> Short: 15)
defaults -currentHost write ~/Library/Preferences/ByHost/.GlobalPreferences.plist InitialKeyRepeat -int 15
defaults write ~/Library/Preferences/.GlobalPreferences.plist InitialKeyRepeat -int 15
defaults write .GlobalPreferences InitialKeyRepeat -int 15

# Keyboard/Key Repeat (Slow: 120 <---> Fast: 2)
defaults -currentHost write ~/Library/Preferences/ByHost/.GlobalPreferences.plist KeyRepeat -int 2
defaults write ~/Library/Preferences/.GlobalPreferences.plist KeyRepeat -int 2
defaults write .GlobalPreferences KeyRepeat -int 2

# Mouse/Tracking speed (Slow: 0 <---> Fast: 3)
# /Library/User\ Template/Non_localized/Library/Preferences
# defaults read /Library/User\ Template/Non_localized/Library/Preferences/.GlobalPreferences
defaults -currentHost write ~/Library/Preferences/ByHost/.GlobalPreferences.plist com.apple.mouse.scaling -float 3.0
defaults write ~/Library/Preferences/.GlobalPreferences.plist com.apple.mouse.scaling -float 3.0
defaults write .GlobalPreferences com.apple.mouse.scaling -float 3.0

# Mouse/Scrolling speed (Slow: 0 <---> Fast: 5)
# defaults write /Library/User\ Template/Non_localized/Library/Preferences/.GlobalPreferences com.apple.scrollwheel.scaling -float 5.0
defaults -currentHost write ~/Library/Preferences/ByHost/.GlobalPreferences.plist com.apple.scrollwheel.scaling -float 5.0
defaults write ~/Library/Preferences/.GlobalPreferences.plist com.apple.scrollwheel.scaling -float 5.0
defaults write .GlobalPreferences com.apple.scrollwheel.scaling -float 5.0

# Mouse/Double-Click speed (Slow: 5 <---> Fast: 0.15)
# defaults write /Library/User\ Template/Non_localized/Library/Preferences/.GlobalPreferences com.apple.mouse.doubleClickThreshold -float 5.0
defaults -currentHost write ~/Library/Preferences/ByHost/.GlobalPreferences.plist com.apple.mouse.doubleClickThreshold -float 5.0
defaults write ~/Library/Preferences/.GlobalPreferences.plist com.apple.mouse.doubleClickThreshold -float 5.0
defaults write .GlobalPreferences com.apple.mouse.doubleClickThreshold -float 5.0

# Mouse/Scroll direction: Natural (Lion-style: true <---> general: false)
# defaults write /Library/User\ Template/Non_localized/Library/Preferences/.GlobalPreferences com.apple.swipescrolldirection -bool false
defaults -currentHost write ~/Library/Preferences/ByHost/.GlobalPreferences.plist com.apple.swipescrolldirection -bool false
defaults write ~/Library/Preferences/.GlobalPreferences.plist com.apple.swipescrolldirection -bool false
defaults write .GlobalPreferences com.apple.swipescrolldirection -bool false

# General/Automatically hide and show the menu bar (Hide: true <---> Reveal: false)
defaults -currentHost write ~/Library/Preferences/ByHost/.GlobalPreferences.plist _HIHideMenuBar -bool true
defaults write ~/Library/Preferences/.GlobalPreferences.plist _HIHideMenuBar -bool true
defaults write .GlobalPreferences _HIHideMenuBar -bool true

defaults write com.tinyspeck.slackmacgap SlackNoAutoUpdates -bool YES
defaults write com.google.Keystone.Agent checkInterval 0

#pkill -u "${USER}" -l "^/usr/sbin/cfprefsd agent$" 2>/dev/null
#pkill -u "${USER}" -f "^/System/Library/CoreServices/Finder.app/Contents/MacOS/Finder$" 2>/dev/null
#killall Xcode
#defaults -currentHost read ~/Library/Preferences/ByHost/.GlobalPreferences.plist
#defaults read ~/Library/Preferences/.GlobalPreferences.plist

for app in "Activity Monitor" \
		"cfprefsd" \
		"Xcode" \
		"Finder"; do
		killall "${app}" &> /dev/null
done

# launchctl unload ~/Library/LaunchAgents/LoginScripts.plist
launchctl load ~/Library/LaunchAgents/LoginScripts.plist
launchctl start LoginScripts.plist
launchctl load ~/Library/LaunchAgents/UsbDelay.plist

echo "$(date) : Setting Finished."
