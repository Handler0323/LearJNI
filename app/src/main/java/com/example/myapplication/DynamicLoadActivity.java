package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.example.myapplication.databinding.ActivityMainBinding;
import com.example.myapplication.load.JNIDynamicLoad;

public class DynamicLoadActivity extends AppCompatActivity {


    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        JNIDynamicLoad jniDynamicLoad = new JNIDynamicLoad();
        binding.sampleText.setOnClickListener(v -> binding.sampleText.setText(jniDynamicLoad.getNativeString()));

    }

}