#pragma once
#include <SFML/Graphics.hpp>

namespace Global
{
    class Config
    {
    public:
        static const sf::String game_logo_texture_path;
        static const sf::String background_texture_path;
        static const sf::String player_texture_path;

        static const sf::String subzero_texture_path;
        static const sf::String zapper_texture_path;
        static const sf::String thunder_snake_texture_path;
        static const sf::String ufo_texture_path;
        static const sf::String bunker_texture_path;

        static const sf::String explosion_texture_path;

        static const sf::String shield_texture_path;
        static const sf::String triple_laser_texture_path;
        static const sf::String rapid_fire_texture_path;

        static const sf::String player_bullet_texture_path;
        static const sf::String laser_bullet_texture_path;
        static const sf::String torpedo_texture_path;
        static const sf::String frost_beam_texture_path;

        static const sf::String menu_button_texture_path;
        
        static const sf::String ArcadeI_font_path;
        static const sf::String ArcadeN_font_path;

        static const sf::String background_music_path;
        static const sf::String button_click_sound_path;
        static const sf::String bullet_fire_sound_path;
        static const sf::String powerup_enabled_sound_path;
        static const sf::String powerup_disabled_sound_path;
    };
}