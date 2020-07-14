clear;clc;

load abalone_dataset.mat

label_y =  abaloneTargets.';
eigvalues = abaloneInputs.';
train_label = label_y(1:3500);
train_data = eigvalues(1:3500,:);

%31.6
%model = libsvmtrain(train_label,train_data,'-s 0 -t 0 -c 11 -h 0');


model = libsvmtrain(train_label,train_data,'-s 0 -t 0 -r 10 -c 11');


test_label = label_y(3501:4000);
test_data = eigvalues(3501:4000,:);

[predict_label,accuracy,dec_value] = libsvmpredict(test_label,test_data,model);