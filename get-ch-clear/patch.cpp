#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
   void evaluate(Context ctx) {
       // The node responds only if there is an input pulse
       if (!isInputDirty<input_UPD>(ctx))
           return;

       auto sensor = getValue<input_DEV>(ctx);

       uint16_t cl, cl0, cl1, avg;
       cl = sensor->getChannel(AS7343_CHANNEL_CLEAR);
       cl0 = sensor->getChannel(AS7343_CHANNEL_CLEAR_0);
       cl1 = sensor->getChannel(AS7343_CHANNEL_CLEAR_1);

       avg = round((cl+cl0+cl1)/3);

       emitValue<output_VALUE>(ctx, avg);

       emitValue<output_DONE>(ctx, 1);

    }
}
