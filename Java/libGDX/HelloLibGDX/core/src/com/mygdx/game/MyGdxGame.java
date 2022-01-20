package com.mygdx.game;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.utils.ScreenUtils;

public class MyGdxGame extends ApplicationAdapter {
	
	SpriteBatch batch;
	Texture img;
	CardManager manager;
	
	@Override
	public void create () {
		batch = new SpriteBatch();

		manager = new CardManager();
		
		img = new Texture("Cards/c12.png");

		manager.BuildDeck();
	}

	@Override
	public void render () {
		batch.begin();
		batch.draw(img, 0, 0);
		batch.end();
	}
	
	@Override
	public void dispose () {
		batch.dispose();
	}
}
