#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
   void evaluate(Context ctx) {
       // The node responds only if there is an input pulse
       if (!isInputDirty<input_UPD>(ctx))
           return;

       auto sensor = getValue<input_DEV>(ctx);

       emitValue<output_VALUE>(ctx, sensor->getChannel(AS7341_CHANNEL_415nm_F1));

       emitValue<output_DONE>(ctx, 1);

    }
}
